// Room: /d/huangshan/qingliang.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����̨");
	set("long", @LONG
���˻�ɽ���ճ������ڣ�ÿ���峿�����˵���������յ�Σ����
��Զ����ֻ�������Ƶ�����ƽ�̣��������ʱ���ޡ���Ρ���Ⱥ���
��û���ƺ�֮�С�������ʵ���ǰױ������ʹ����ĳ�ϼ���Ʋ�����
���ĺ��Խ��Խ����ֱ�����ֻ�������ƺ����ڿն������þõ����˻�
ζ��
LONG
	);
	set("exits", ([ 
		"northwest" : __DIR__"diezhang",
		"northeast" : __DIR__"feilong",
		"southup"   : __DIR__"shizi",
		"westup"    : __DIR__"qingliangf",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
