// Room: /qingcheng/zoulang3.c
// Date: Aug. 10 1998 by Winder

inherit RESTROOM_OUT;
void create()
{
	set("short", "�ɷ�����");
	set("long", @LONG
�������ɷ�����������������������ȣ��ɷ�۸ߴ�ɽ��������
����ȥ����ɽ��ţ��Ĺȷ��������챡��ʱʱ��ɢ�ڳ��ִ���֮�䡣��
�źųƣ�����������ġ��������ڴ���ζ�������ϱ��ǿͷ��������ǳ�
�������߳��������ŵ��Ǳ��ɵ��ӵ�������Ϣ�ҡ�
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"east"  : __DIR__"caochang",
		"north" : __DIR__"chufang",
		"south" : __DIR__"kefang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -840);
	set("coor/z", 90);
	set("door_name","����");
	set("door_dir","west");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","���Ϲ��˸����ӣ���Ϣ�С�\n");
	set("no_one_msg",   "���Ϲ��˸����ӣ���ǵ�����Ϣ�ҡ�\n");
	set("inside_msg",   "���Ϲ��˸����ӣ�����һ�Ρ��������죡\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
