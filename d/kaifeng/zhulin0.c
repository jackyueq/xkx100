// /kaifeng/zhulin0.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "����");
	set ("long", @LONG
һ��������ͷ�����̵�������б�����������ɫ�Ĺ��͸����Ҷ��
�����������������ˢˢ����������Զȥ�������ֵ��м䱻�˿�����
һƬ�յأ�������һ��Сé�ݡ�
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"enter" : __DIR__"zhulin1",
		"west":__DIR__"fanta",
	]));
	setup();
	replace_program(ROOM);
}
