// Room: /d/taohua/hall.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

string look_bagua();

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ǳ����ķ�����ǽ�Ϲ������������ֻ����������Ǻ�
�ں����ľ�Ʒ���������֮�϶��Ű�Ƭ��Ƭ�� ��������(bagua)ͼ����
ȴ�ֲ���Ѱ���İ�����ô�ŵ����룬�������䣬��б���ƣ���Ȼ������
�Ĳ��ü���Э����������ź�����һƬ���֡�
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"zoulang4",
		"west"  : __DIR__"zoulang1",
		"south" : __DIR__"hetang",
		"north" : __DIR__"jingshe",
	]));
	set("item_desc", ([
		"bagua" : (: look_bagua :),
	]) );
	set("objects", ([
		__DIR__"npc/shitong":1,
		CLASS_D("taohua")+"/first": 1,
	]));
	set("valid_startroom", 1);
	set("coor/x", 9010);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	"/clone/board/taohua_b"->foo();
}

string look_bagua()
{
	int i, j, temp;
	int *bagua = ({0,1,2,3,4,5,6,7});
	string *bagua_name = ({"��","��","��","��","��","��","��","Ǭ"});
	string result;
	object me = this_player();

	for (i = 0; i < 8; i++)
	{
		j = random(8);
		while (j == i)
			j = random(8);
		temp = bagua[i];
		bagua[i] = bagua[j];
		bagua[j] = temp;
	}		
	for (i = 1; i < 9; i++)
		me->set_temp("bagua_" + i, bagua[i - 1]);
	result = "һ����ֵ������ԣ����水˳ʱ��˳�������ţ�";
	for (i = 0; i < 8; i++)
		result += bagua_name[bagua[i]];
	return result + "��\n";
}

