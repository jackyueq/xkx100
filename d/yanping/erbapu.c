// Room: /d/yanping/erbapu.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "إ����");
	set("long", @LONG
إ���̸߾���ϼ���ϣ�����Ⱥɽ���࣬������ڣ�ʮ��ˬ��������
�Ǹ���С��С���䣬��Ȼ���������Ŀ��̷��࣬����Ҳֻ��һ��СС��
�꣬��������һ�������������ط�Ϊ����������ϼʼΪ�ɡ�����������
֮�衣
LONG );
	set("exits", ([
		"north"     : __DIR__"xianxialing",
		"southdown" : __DIR__"shandao1",
		"west"      : __DIR__"kedian",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 2,
	]));
	set("outdoors", "jiangnan");
	set("coor/x", 1500);
	set("coor/y", -4000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
