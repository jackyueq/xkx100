// Room: /d/suzhou/zhonglou.c
// Last Modified by winder on May. 15 2001
inherit ROOM;
void create()
{
	set("short", "��¥");
	set("long", @LONG
����һ��שľ�ṹ�ı����������߲㣬�������˽��Σ��������ᣬ
�ܽ��Ϲ�����һ����Сͭ�壬��綣�����졣����ǽ���οյ��������
�����ǵ�����һ������̬άФ��������������֮�֡�������ڴ�����
һ�ȹ��ε�Сľ�ţ����������ò���Ϳ�棬��������������ɽ��������
�𽲾�ʱ�����Ρ�
LONG
	);
	set("outdoors","suzhou");
	set("exits", ([
		"east" : __DIR__"lingyansi",
//		"enter" : __DIR__"zhonglou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 895);
	set("coor/y", -1120);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

