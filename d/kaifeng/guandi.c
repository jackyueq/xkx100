// /kaifeng/guandi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�ص���");
	set("long", @LONG
�ص���ǰһ���ϴ������¯����Ϊ����ү�������š����������Ƕ�
��Э����Ҫ��һ�¹ص�ү�����ϣ����������е�ʤ���ˣ�Ҳ��Ҫ����
�������㡣�Ͼ��ص��ֱ���Ϊ��ʥ��
LONG);
	set("objects", ([
		__DIR__"npc/obj/guanyu" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"paifang",
	]));
	setup();
	replace_program(ROOM);
}
