//ROOM: shufang.c

inherit ROOM;

void create()
{
	set("short", "�߷���");
	set("long",@LONG
���ǡ����չ������鷿����ǽ�ڷ���һ����ܣ����������������
�����鼮������������һ��īɫС�������ϵ���¯ð���������̣���ǰ
�и����ſɹ�����������������֮���������㲻�ɵͺ�������һ��
�ž����ڣ���
LONG );
	set("exits", ([
		"west" : __DIR__"men2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50990);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}