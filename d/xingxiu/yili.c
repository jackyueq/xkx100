// /d/xingxiu/beijiang.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����λ�ڱ�����ɽѩˮ�㼯���ɵ�������Ա������ھ۾���ά���
���ˣ�����������ʮ�����֡�ֻ������˵�Ļ����������������м�С��
�̣��������������У������ھ���ʲô������������һ�ҿ�ջ����ջ��
��һ����ǡ������м�Ժ�䣬Ժ�ſ��пô�����
LONG );
	set("exits", ([ 
	    "west"      : __DIR__"store",
	    "east"      : __DIR__"house",
	    "south"     : __DIR__"yiligate",
	    "northwest" : __DIR__"saimachang",
	    "north"     : __DIR__"kezhan",
	]));
	set("objects", ([
		__DIR__"npc/woman": 2 ]) );
//	set("no_clean_up", 0);
	set("outdoors", "xiyu");

	set("coor/x", -39000);
	set("coor/y", 13000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

