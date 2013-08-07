// Room: /d/taishan/riguan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�չ۷�");
	set("long", @LONG
�չ۷�λ����ʶ����ϣ��ųƽ����ң���ɹ��ճ��������ഫ�ڷ�
���������أ��Ͽ���Խ�����ֳ��ع۷塢Խ�۷塣�����ʯ�ܴأ����
�ĵط�һʯ׿������Ϊ���ӷ塣�����߱���ͨ��̩ɽ�����ŵ�ɽ·��
LONG );
	set("exits", ([
		"south"     : __DIR__"aishen",
		"eastup"    : __DIR__"tanhai",
		"eastdown"  : __DIR__"riguanroad1",
		"northwest" : __DIR__"yuhuang",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/tianmen" : 1,
	]));
	set("valid_startroom", 1);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 770);
	set("coor/z", 210);
	setup();
	"/clone/board/taishan_b"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir != "northwest" &&
		me->query("family/family_name") !="̩ɽ��" &&
		present("tianmen daoren", environment(me)) &&
		living(present("tianmen daoren", environment(me))))
	{
		return notify_fail("���ŵ��˺ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
	}
	else return ::valid_leave(me, dir);

}
