// Room: /d/hengshan/hufengkou.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�� "������" �� "����ͤ" ���͵���һ�����·ת�Ķ���·�ڣ�
������һ����ڣ�������������绢Х���ȱ�ǿ����࣬������
����
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southwest" : __DIR__"daziling",
           "west"      : __DIR__"xuangengsong",
           "northeast" : __DIR__"guolaoling",
        ]));
        set("outdoors", "hengshan");
        set("no_clean_up", 0);
        set("coor/x", 20);
	set("coor/y", 3150);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}

