//room: changl4.c
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ���
�������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô������
�ģ��������������Ϣ����ֻ�е���������ģ��ǳ���������ȶ�����
һ�䷿�䣬���治ʱ��������Ů�ӵĽ�߳��
LONG );
	set("exits",([
		"north" : __DIR__"changl3",
		"east" : __DIR__"liangong",
		"west" : __DIR__"changl8",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50980);
	set("coor/y", 30140);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}