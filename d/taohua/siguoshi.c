inherit RESTROOM_OUT;

void create()
{
	set("short", "˼����");
	set("long", @LONG
�����һ����Ϲ����ŵ��ӱ���˼���ĵط��������������һ�Ŵ���
�Եÿյ����ġ��������ǹ�ͺͺ��ǽ�ڣ�����ȥ������ģ�ԭ��ȴ����
���ġ����ŵĵط���һС�������߷���һֻ�롣������һ�䲻���۵�С
�ݣ����Ϲ��˸����ӡ��һ�������
LONG );
	set("exits", ([
		"south"  : __DIR__"liangongfang",
	]));
	set("objects", ([
		__DIR__"npc/mei" : 1,
	]) );	
//	set("no_clean_up", 0);
	set("coor/x", 8980);
	set("coor/y", -2990);
	set("coor/z", 0);
	set("door_name","��");
	set("door_dir","west");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","���Ϲ��˸����ӣ��һ�����\n");
	set("inside_msg",   "���Ϲ��˸����ӣ�����һ�Ρ��������죡\n");
	set("no_one_msg",   "���Ϲ��˸����ӣ��һ���������Ϣ�ҡ�\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
