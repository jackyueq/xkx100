//room: changlang2.c
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ���
�������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô������
�ģ��������������Ϣ����ֻ�е���������ģ��ǳ������һ������
�����ߴ�����
LONG );
	set("exits",([
		"east" : __DIR__"changl3",
		"west" : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50990);
	set("coor/y", 30150);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}