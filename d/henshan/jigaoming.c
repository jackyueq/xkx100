// Room: /d/henshan/jigaoming.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������̨");
        set("long", @LONG
�����Ǹ�������ߴ����������������� "������" ���������ڴˣ�
�⼴���༫�� (���޼�����) ����⼫�� (����������) ������������
�ϵģ���Ի������̨��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"sansheng",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
