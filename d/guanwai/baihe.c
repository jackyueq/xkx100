// /guanwai/baihe.c

inherit ROOM;

void create()
{
	set("short", "�׺�");
	set("long", @LONG
�����ǳ���ɽ�µ�һ��С�壬ֻ���ģ�����ª��Сľ�ݡ����ﲢ
û�й̶��ľ���ľ�ݶ��ǽ�ɽ�ɲεĲο����ǣ�Ϊ�����ڽ�ɽǰ����
����úõ���Ϣһ�¡��������Ρ�������ĳ��״�ɽ��
LONG );
	set("exits", ([
		"west"  : __DIR__"caoguduo",
		"east"  : __DIR__"milin1",
		"north" : __DIR__"xiaowu",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "changbai");
	set("coor/x", 6140);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
