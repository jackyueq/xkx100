// Room: /d/taishan/baihe.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�׺�Ȫ");
	set("long", @LONG
�ഫ��ǰ������һ���׺�Ȫ������ˮ��������Ϊ̩ɽ֮���Ȫ
ˮ����ӿ�����ϣ������ˮ���ɺ������ų��ϴ��һ��������Ϊ������
ϧ������һ����˽������С�٣�������Ȫˮ�������������ŷ�ˮ֮˵��
��Ȫ�۶������׺�Ȫ�Ӵ˱�ɺ��ˡ�����ֻʣ��һ�����š��׺�Ȫ����
�ֵ�ʯ����Ϊ���������������ϣ�������ɽ֮·��
LONG );
	set("exits", ([
		"northup"   : __DIR__"hongmen",
		"southdown" : __DIR__"daizong",
	]));
	set("resource/water",1);
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
	if(!userp(me) && (int)me->query("ts_xl") && dir=="southdown")
		return 0;
	return ::valid_leave(me,dir);
}

