// Room: /d/henshan/denggaotai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�Ǹ�̨");
        set("long", @LONG
�����������ŵǸ���Զ�ĺ�ȥ������վ�����������壬������
���衣���潭��ȥ������ű���ʱ��ʱ�֡���Χ��ϼ�����ޣ��ϸǣ���
����廷����������ǧ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"nantian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -320);
	set("coor/y", -1030);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
