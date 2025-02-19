// Automatically generated by Diplomat

#pragma warning disable 0105
using System;
using System.Runtime.InteropServices;

using DiplomatFeatures.Diplomat;
#pragma warning restore 0105

namespace DiplomatFeatures;

#nullable enable

public partial class Foo: IDisposable
{
    private unsafe Raw.Foo* _inner;

    /// <summary>
    /// Creates a managed <c>Foo</c> from a raw handle.
    /// </summary>
    /// <remarks>
    /// Safety: you should not build two managed objects using the same raw handle (may causes use-after-free and double-free).
    /// </remarks>
    /// <remarks>
    /// This constructor assumes the raw struct is allocated on Rust side.
    /// If implemented, the custom Drop implementation on Rust side WILL run on destruction.
    /// </remarks>
    public unsafe Foo(Raw.Foo* handle)
    {
        _inner = handle;
    }

    /// <returns>
    /// A <c>Foo</c> allocated on Rust side.
    /// </returns>
    public static Foo New(string x)
    {
        unsafe
        {
            byte[] xBuf = DiplomatUtils.StringToUtf8(x);
            nuint xBufLength = (nuint)xBuf.Length;
            fixed (byte* xBufPtr = xBuf)
            {
                Raw.Foo* retVal = Raw.Foo.New(xBufPtr, xBufLength);
                return new Foo(retVal);
            }
        }
    }

    /// <returns>
    /// A <c>Bar</c> allocated on Rust side.
    /// </returns>
    public Bar GetBar()
    {
        unsafe
        {
            if (_inner == null)
            {
                throw new ObjectDisposedException("Foo");
            }
            Raw.Bar* retVal = Raw.Foo.GetBar(_inner);
            return new Bar(retVal);
        }
    }

    /// <summary>
    /// Returns the underlying raw handle.
    /// </summary>
    public unsafe Raw.Foo* AsFFI()
    {
        return _inner;
    }

    /// <summary>
    /// Destroys the underlying object immediately.
    /// </summary>
    public void Dispose()
    {
        unsafe
        {
            if (_inner == null)
            {
                return;
            }

            Raw.Foo.Destroy(_inner);
            _inner = null;

            GC.SuppressFinalize(this);
        }
    }

    ~Foo()
    {
        Dispose();
    }
}
