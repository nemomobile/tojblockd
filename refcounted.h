/*
 * Copyright (C) 2013-2014 Jolla Ltd.
 * Contact: Richard Braakman <richard.braakman@jollamobile.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/*
 * Base class for objects with reference counts.
 */
class Refcounted {
public:
    Refcounted() : m_refs(0) { }
    virtual ~Refcounted() { }

    int m_refs;

    void deref() { if (--m_refs == 0) final_deref(); }
    void ref() { ++m_refs; }

    virtual void final_deref() { delete this; }
};
