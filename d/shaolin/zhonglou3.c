// Room: /d/shaolin/zhonglou3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
���������ƺ�Խ��Խխ��¥��Ҳ��Ϊ���ơ������ϲ�����
������������ľ����ɫҲ���¾ɲ�ͬ���Ӵ�����������������
�Կ��������еĲؾ�¥�ͷ���¥¶������һ�ǣ��������Ǻ��
���ݶ����ݼ������˸����ġ����֡�
LONG );
	set("exits", ([
		"up" : __DIR__"zhonglou4",
		"down" : __DIR__"zhonglou2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 830);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}