// Room: /d/xingxiu/tugu.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "�¹Ȼ��ٹ��");
	set("long", @LONG
�������¹Ȼ붼�ǡ��¹Ȼ�ԭΪ�ʱ���һ֧�������ڱ�����������
���¹Ȼ���������Ǩ�ڴˡ����¹Ȼ�Ϊ��������ɺ��������ڷ�ٹ���ڡ�
���ڻ������Χ�Ķ�����壬���ڴ���Ͽ������������޲�͸�����档
LONG);
	set("outdoors", "xiyu");
	set("exits", ([
		"east"      : __DIR__"shazhou",
		"northwest" : __DIR__"silk5",
		"south"     : __DIR__"nanjiang",
	]));

	set("objects", ([
		__DIR__"npc/trader" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -23500);
	set("coor/y", 900);
	set("coor/z", 0);

	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

