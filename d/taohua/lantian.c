// Room: /d/taohua/lantian.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
inherit ROOM;
 
void create()
{
	set("short", "����");
	set("long",@LONG
�������������죬��׵�����Ʈ�����ϵ����˿����������ϡ���......
��ˬ������������һ�ָо�����������һ���˼�С��
LONG);   
	set("outdoors", "taohua");
	set("no_clean_up", 0);
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
