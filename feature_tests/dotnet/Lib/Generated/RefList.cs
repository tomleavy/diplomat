// Automatically generated by Diplomat

#pragma warning disable 0105
using System;
using System.Runtime.InteropServices;

using DiplomatFeatures.Diplomat;
#pragma warning restore 0105

namespace DiplomatFeatures;

#nullable enable

public partial class RefList: IDisposable
{
    private unsafe Raw.RefList* _inner;

    /// <summary>
    /// Creates a managed <c>RefList</c> from a raw handle.
    /// </summary>
    /// <remarks>
    /// Safety: you should not build two managed objects using the same raw handle (may causes use-after-free and double-free).
    /// </remarks>
    /// <remarks>
    /// This constructor assumes the raw struct is allocated on Rust side.
    /// If implemented, the custom Drop implementation on Rust side WILL run on destruction.
    /// </remarks>
    public unsafe RefList(Raw.RefList* handle)
    {
        _inner = handle;
    }

    /// <returns>
    /// A <c>RefList</c> allocated on Rust side.
    /// </returns>
    public static RefList Node(int data)
    {
        unsafe
        {
            int* dataRaw;
            dataRaw = data;
            Raw.RefList* retVal = Raw.RefList.Node(dataRaw);
            return new RefList(retVal);
        }
    }

    /// <summary>
    /// Returns the underlying raw handle.
    /// </summary>
    public unsafe Raw.RefList* AsFFI()
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

            Raw.RefList.Destroy(_inner);
            _inner = null;

            GC.SuppressFinalize(this);
        }
    }

    ~RefList()
    {
        Dispose();
    }
}
