// /kaifeng/longting.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��ͤ���");
	set("long", @LONG
��ͤ���ԭ���ǵ����й���������֮�󣬹����Ƿϣ������ڴ˵ظ�
���������䱦�ֳ¸���ֱ��������̾Ϊ��ֹ�����ϱ������֮��
�ɡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"tingyuan",
	]));

	setup();
	replace_program(ROOM);
}
