// Automatically generated by Diplomat

#pragma warning disable 0105
using System;
using System.Runtime.InteropServices;

using DiplomatFeatures.Diplomat;
#pragma warning restore 0105

namespace DiplomatFeatures;

#nullable enable

public partial class ErrorStructException : Exception
{
    private ErrorStruct _inner;

    public ErrorStructException(ErrorStruct inner) : base("ErrorStruct error occurred")
    {
        _inner = inner;
    }

    public ErrorStruct Inner
    {
        get
        {
            return _inner;
        }
    }
}
