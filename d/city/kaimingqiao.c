// Room: /yangzhou/kaimingqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
    set("long",@LONG
ʰ�����ϣ����Ͽ�����ͷ��������Χ��ʯ����ÿ��ʯ����������
ʱ��ľ����̾��£����ξ������������ĵ�ʯ������һ�Ҷ�����š���
�����ž�˵�����ݳ�������ϵ��ţ��������ս��֮���Ҵ�����������
�����˶Կ����Ŷ��ип������˶��ߵ�ʯ�ף����ǲ��½ֿڣ���������
���֣�ͨ��ѧ��������Ժ����
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"qionghuajie",
		"east"  : __DIR__"caiyijiekou",
	]));
	set("objects", ([
		"/d/village/npc/kid": random(4),
		"/d/village/npc/girl": random(3),
		"/d/village/npc/boy": random(3),
	]));
	set("coor/x", 30);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}