// Room: /yangzhou/waifang.c
// Last Modified by Winder on Jul. 20 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","����¥");
	set("long",@LONG
�ⷿ�������ţ�������������Ļ���������������ձ�������˰���
�����й�������ģ�ϵ�桶���š�ȫ���������ľ��Ȼ��������ʯ����
ľ������ͭƿ��������һ֦������λ����Ҷ���齴�����ľԲ̨������
���ɡ�����һɴ�����������������ж��졣
LONG );
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"woshi",
		"south" : __DIR__"meixiangyuan",
	]));
	set("objects", ([
		__DIR__"npc/lulixian" : 1,
	]));
	create_door("east", "ɴ����", "west" , DOOR_CLOSED); 
	set("coor/x", 41);
	set("coor/y", 21);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}