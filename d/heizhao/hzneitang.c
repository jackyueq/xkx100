// Room: /heizhao/hzneitang.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����м䰲��һ�ų��������������յ�͵ƣ��ų������֮
�Ρ�������һ�����ϣ����¶���һ��ͷ�����׵�Ů�ӣ�����������
��Ŀ���ŵ���һ������Լ�Ĵ磬��Լ���֣������õ����ӣ���Ȼ��
��Ǳ��˼�������������˽�����ȴ��̧ͷ��
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"hzyuanzi",
		"north" : __DIR__"hzneishi",
	]));
	set("objects", ([
		__DIR__"npc/yinggu" : 1,
	]));
	set("coor/x", -5100);
	set("coor/y", -1480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}