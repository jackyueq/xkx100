// Room: /d/wuyi/yuchayuan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
����԰λ�������ϱߵ�һ��ƽ���ϡ�Ԫ����һ���и��˵Ĺ���Ϊ��
���ϣ���ʵ����˼������ġ�ʯ�顱���Ӵˣ������ʮ��ġ�ʯ�顱��
�������γ簲�����������Ϊ���Դγ�ã��������������ʵۣ���
�˽�����ʢ��һʱ������԰��ÿ�ꡰ���ݡ���һ�죬��ɽ̨�����󡰲�
��ѿ�ˣ��跢ѿ�ˣ����ĺ�������ʱʱ�ۻ������µ����Ρ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"tongxianjing",
		"north" : __DIR__"5qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1380);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

