//room: changlang12.c
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ���
�������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô������
�ģ��������������Ϣ����ֻ�е���������ģ��ǳ���������ȶ���ͨ
���鷿��
LONG );
	set("exits",([
		"east" : __DIR__"men2",
		"west" : __DIR__"changl9",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51010);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}