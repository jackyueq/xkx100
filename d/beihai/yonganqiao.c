// /d/beihai/yonganqiao.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
���������������ϣ����������ƻ����š�������ȯ���������Σ���
������ʯ���¶�ƽ�������������е�̾�������������������ϱ��ֱ�
����������¥ʽľ�Ʒ�һ������Ͳ�߶������ɫԲ����ɫ�����޶�Ŀ��
LONG
	);
	set("exits", ([
		"north" : __DIR__"yongansi",
		"south" : __DIR__"zhaojing",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
