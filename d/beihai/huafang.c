// /d/beihai/huafang.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����ի");
	set("long", @LONG
�姽���֮����ի���ֳ�ˮ�Ϊһ���Ʒ�����Ӿ�ضԳƲ���֮ͥ
Ժ������������ͨ�������������ϣ��Գ�ˮΪ���ģ���Ϊ���������
�����ֱ��Ǿ��㣬�����ң��������Ȼر�������һ����ʤ��ͥԺ���ſ�
ͥǰ��һ��׳��ï�ĹŻ����ഫ����ǧ�꣬ͥ�����ſ¡�
LONG
	);

	set("exits", ([
		"north"     : __DIR__"houmen",
		"southwest" : __DIR__"dongmen",
		"southeast" : __DIR__"haopu",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -160);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
