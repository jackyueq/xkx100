// Room: /d/xingxiu/yili1.c
// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "���������");
	set("long", @LONG
���磬������Զ����ͨ��˹���ϵ����ã��������ء�������������
������ͨ��Ҫ�壬��˿��֮·����Ҫ����վ֮һ�������ǽ������ӱ�
���ȵض������Ǹ�һ���ģ�������Ҫ����ǽ����������̨��ǹ�ۣ��䱸
ɭ�ϡ�
LONG
	);
	set("outdoors", "xiyu");
	set("exits", ([
		"south" : __DIR__"yilihe",
		"north" : __DIR__"yili",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/trader" : 1,
	]));
	set("coor/x", -39000);
	set("coor/y", 12000);
	set("coor/z", 0);
	setup();
//	quarter_pass();
}
/*
void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21)
	{
		set("long", @LONG
���磬������Զ����ͨ��˹���ϵ����ã��������ء�������������
������ͨ��Ҫ�壬��˿��֮·����Ҫ����վ֮һ�������ǽ������ӱ�
���ȵض������Ǹ�һ���ģ�������Ҫ����ǽ����������̨��ǹ�ۣ��䱸
ɭ�ϡ�������ҹ�䣬�����ѹأ�ֻ�м�������ʿ���ڳ��ſ���ҹ��
LONG);
		delete("exits/north");
	}
	else {
		set("long", @LONG
���磬������Զ����ͨ��˹���ϵ����ã��������ء�������������
������ͨ��Ҫ�壬��˿��֮·����Ҫ����վ֮һ�������ǽ������ӱ�
���ȵض������Ǹ�һ���ģ�������Ҫ����ǽ����������̨��ǹ�ۣ��䱸
ɭ�ϡ�
LONG);
		set("exits/north", __DIR__"yili2");
	}
	call_out("quarter_pass", 30);
}
*/
