// Room: /d/huijiang/zoulang2.c
// Last Modified by winder on Sep. 12 2001

inherit RESTROOM_OUT;

void create()
{
	set("short", "����");
	set("long",@LONG
������һ�������������ϣ�����û��һ���ˣ���ĽŲ������ú�Զ��
���Գ�����Ĳк���ͣ�˼�ֻ�����ҽе����ܣ�������紵����������
���ϱ��ƺ���һ���š�
LONG );
	set("outdoors", "huijiang");	
	set("exits", ([
		"west"     : __DIR__"yixiangting",
		"northup"  : __DIR__"zongduo",
		"eastdown" : __DIR__"zoulang1" ,
	]));
	set("no_clean_up", 0);
	set("coor/x", -50070);
	set("coor/y", 9140);
	set("coor/z", 10);
	set("door_name","��");
	set("door_dir","south");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","���Ϲ��˸����ӣ���Ϣ�ҡ�\n");
	set("no_one_msg",   "���Ϲ��˸����ӣ���Ϣ�ҡ�\n");
	set("inside_msg",   "���Ϲ��˸����ӣ�����һ�Ρ��������죡\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
