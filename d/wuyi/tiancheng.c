// Room: /d/wuyi/tiancheng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�����Ժ");
	set("long", @LONG
��Х�ָ߾ӻ�Х���ϣ�������Ϊ����ɽ�͵����ġ����������ʮ��
�꣬���ڴ��㽭������ͯ������һλ�����Ժյ�Ȫ�����У�����������
�֣���Х�ֲ���ʽ����Ϊ�������Ժ�����ݻ�Х����ȥ�������ޱȣ���
����˫��������Ҫ�����������η������ȴ���������������ʫ��д
��������Ŀ��ͼ������Ȼ����Υ����
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"huxiaoyan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng": random(3),
	]));
	set("coor/x", 1390);
	set("coor/y", -5040);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

