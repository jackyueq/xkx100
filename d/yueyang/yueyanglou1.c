// Room: /d/yueyang/yueyanglou1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����¥ʼ�����ƣ����������ǣ����ͥ����ң�Ծ�ɽ����������
�����ϼ��潭����¥Զ����һ�����󣬰׷���㣬��Ӱ���⣬������ǧ��
ȫ¥�����ɣ�������ܣ�¥������״����һ������ͷ�����׳ƿ��
    ���ΰ��꿤�����Ӿ���������¥��ƾ��Զ����ʫ�˴󷢣�����ˮ��
�죬���ˮ�������ֳ��塣����С��季����������󣬲��������ǡ���
�������ܹ�ɪ����Ȼ�������顣΢�����ƶ���ܰ�������˲�����������
���ࡣ��������Ӧ���Ӿ�֮�룬Ϊ������¥�ǡ���������ʮ�֣�¥ʼ��
������֮�Ƕ��ǣ�������֮�ֶ��֡���������
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"up"        : __DIR__"yueyanglou2",
		"south"     : __DIR__"xianmeiting",
		"north"     : __DIR__"sanzuiting",
		"eastdown"  : __DIR__"huaiputing",
		"northeast" : __DIR__"xiaoqiaomu",
	]));
	set("coor/x", -1450);
	set("coor/y", -2260);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
