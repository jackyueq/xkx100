// /guanwai/dongcheng.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������û����̾͵Ľֵ������ϵ����˲��࣬�����������塣ż��
�м�������������ε������߹��������������壬����ľ������洫
�����ӵĽ�������������һ�Ż����ݳɵ���������������Ц��������
LONG );
	set("exits", ([
		"west"      : __DIR__"jishi",
		"south"     : __DIR__"tuyaoguan",
		"east"      : __DIR__"xuedi1",
		"northeast" : __DIR__"huandi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6050);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (dir == "east")
	{
		me->receive_damage("qi",30);
		me->receive_wound("qi",30);
	tell_object(me,"һ�ɴ̹ǵĺ��紵������ֻ���û����ѪҺ���챻��ס�ˣ�\n");
	}
	return 1;
}