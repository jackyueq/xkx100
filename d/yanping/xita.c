// Room: /d/yanping/xita.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������ʮ�������£������ھ����Ҷ��������ɣ��߲��
�ǣ�ʵ����ʯ���������ֻ�����ʽ������������ʯ����������¹�ͻ���
����������������֮�����ж�ʯ��(bian)����������һ�����ڷ���
ʯ�ң��ഫ������Ϊ������
LONG );
	set("exits", ([
		"southwest"    : __DIR__"yuandong",
	]));
	set("item_desc", ([
		"bian" : "
��       ��
��       ��
��       ��
��       ��\n\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
