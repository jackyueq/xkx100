// Room: /d/henshan/fangguangsi.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���������������¡��������а˸�ɽͷ�����������꣬�����¾�
�������������ĵ�һƬƽ���ϡ��������ţ��� "���η����£���֪����
֮��" ֮˵���� "������֮��" Ϊ��ɽ���ľ�֮һ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanjian",
           "eastup"     : __DIR__"shanlu10",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", -1050);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
