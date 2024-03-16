if Sys.isapple()
    ext = "dylib"
elseif Sys.islinux()
    ext = "so"
else
    error("Unsupported OS")
end

const LIBBAR = joinpath(@__DIR__, "../build/libbar.$(ext)")


function c_api_bar(v::Vector{Cdouble}, factor::Cint)
    # Cdouble == Float64
    # Cint == Int32

    # C function looks like:
    # void multiply_array(double* arr, int n, int factor);

    ccall(
        (:multiply_array, LIBBAR),      # C function name and library name
        Cvoid,                          # return type of the C function
        (Ptr{Cdouble}, Cint, Cint),  # argument types of the C function
        v, length(v), factor             # arguments to the C function
    )

    # The above function directly modifies the input array `v`
    # So, no need to return anything

    # `Ptr{Cdouble}` is a pointer to `Vector{Cdouble}` and same as `double*` in C
end


function test()
    v = [1.0, 2.0, 3.0]
    factor = Int32(3)

    println("Before: ", v)
    c_api_bar(v, factor)
    println("After : ", v)

    @show v, factor
    @assert all(isapprox.(v, [1.0, 2.0, 3.0] .* factor))
end

test()