// Room: /d/henshan/mojingtai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ĥ��̨");
        set("long", @LONG
ĥ��̨λ���������£����ɽͤһ�����ڡ�̨ǰ���·ת��̨�Թ�
�ɲԴ䣬�������ġ��ഫ�������ڻ����ڴ����� "������" ����̨��
ɮ����������ĥ�����Ƿ����ڵ�һ����̨��������� "ĥ��̨֮��" ��
��ɽ���ľ�֮һ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanlu8",
           "westup"     : __DIR__"shanlu7",
           "northup"    : __DIR__"shanlu6",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1050);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
