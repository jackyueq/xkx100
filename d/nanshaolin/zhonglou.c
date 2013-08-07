// Room: /d/nanshaolin/zhonglou.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥СԺ");
	set("long", @LONG
����һ��שľ�ṹ�ı����������߲㣬�������˽��Σ��������ᣬ
�ܽ��Ϲ�����һ����Сͭ�壬��綣�����졣����ǽ���οյ��������
�����ǵ�����һ������̬άФ��������������֮�֡�������ڴ�����
һ�ȹ��ε�Сľ�ţ����������ò���Ϳ�棬��������������ɽ��������
�𽲾�ʱ�����Ρ�
LONG );

	set("exits", ([
		"west"  : __DIR__"celang-3",
		"enter" : __DIR__"zhlou1",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "enter" ) return 0;
	return ::valid_leave(me, dir);
}

