// Room: /d/nanshaolin/miaofadian.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"���"NOR);
	set("long", @LONG
�����������µ��������������ƣ�᣽Ƕ��ˡ����ʮ�ֵ���
ʢ��������輫Ϊ���ӡ������Ϊ��ӿգ����Բ������������
LONG );
	set("exits", ([
		"south" : __DIR__"stoneroad2",
		"north" : __DIR__"dxshijie",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

