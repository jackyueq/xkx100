// xiaolu2.c
// Last Modified by winder on Aug. 1 2002

inherit RESTROOM_OUT;

void create()
{
	set("short", "Сɽ·");
	set("long", @LONG
�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô�վ���
������������ܾ����ĵģ�������߽���һ��������Դ�����������
һ������(men)��
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"xiaolu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );
	set("no_clean_up", 0);

	set("coor/x", -840);
	set("coor/y", 210);
	set("coor/z", 120);
	set("door_name","����");
	set("door_dir","east");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","���Ϲ��˸����ӣ���ɽС��\n");
	set("inside_msg",   "���Ϲ��˸����ӣ�����һ�Ρ��������죡\n");
	set("no_one_msg",   "���Ϲ��˸����ӣ���ɽ����Ϣ�ҡ�\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
	setup();
}
