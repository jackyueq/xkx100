// Room: /yangzhou/qinshi1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����������麣��ٺ���������Ƕ�����ҡ�ʯ�������С��ͨ����
��ͤ����ɽ�������������������顰���ҡ����ң������������(lian)��
����Ϊ�ο�Ʒ���Ѵ��������ܽ���һ���衱���ʡ�
    ��ǰ�����������Űء��˴���÷Ϊ����һ����˪��ʱ��Ҷδ�伴
�������磬ֱ�������Է�����䣬Ϊ��÷��Ʒ��
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : "
        һ        ��
        ˮ        ��
        ��        ��
        ��        ��
        ��        ź
        ��        ��
        ��        ��
\n",
	]));
	set("exits", ([
		"northwest"  : __DIR__"changchunling",
		"southeast"  : __DIR__"zizaiting",
		"north"      : __DIR__"qishi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}