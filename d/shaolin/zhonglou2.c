// Room: /d/shaolin/zhonglou2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
ÿ��¥���϶������˽�ʵ��ľ¥�壬�˽��ε�ǽ������
�����ȴ󴰡��Ӵ��׿���ǽ��Ҳ�Ǽ�Ϊ��ʵ������������������
���Կ���Χ�����ܵ�С԰�Լ����ߵ����֣����Ʈ��������Ҷ
�����㡣
LONG );
	set("exits", ([
		"up" : __DIR__"zhonglou3",
		"down" : __DIR__"zhonglou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 830);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}