// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ʹ��㳡");
	set("long", @LONG
�����ǻʹ���Ĺ㳡���м���һ����������ʯ��·��·��������
������������ʿ��ʮ��һ�ڣ��岽һ�ڣ������ֳֳ�ǹ��ꪣ��˵���
�ƷǷ������ĵľ����ɴ˿ɼ�һ�ߡ��ϱ��ǻʹ����ţ������������
�����ſ������ڴ�ͭ�ף���������ˮ��
LONG );
	set("exits", ([
		"north" : __DIR__"ysdian",
		"south" : __DIR__"gonggate",
	]));
	set("objects", ([
		__DIR__"npc/gongweishi": 2,
	]));
	set("outdoors", "xixiagong");
	set("coor/x", -17960);
	set("coor/y", 32100);
	set("coor/z", 0);
	setup();
	create_door("south" , "���Ṭ��", "north" , DOOR_CLOSED);
	replace_program(ROOM);
}

