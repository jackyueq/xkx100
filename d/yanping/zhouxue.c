// Room: /d/yanping/zhouxue.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "��ѧ");
	set("long", @LONG
��ƽ���������ͣ��ķ��ʢ�������������ڴ��ι����͡���ʱ����
���塢��������Ĵ��������ڴ˽�ѧ�������˳�Ϊ����ƽ���͡�����
ƽ���౻��Ϊ����ѧ�������������³���������岽һ�ӣ�ʮ��һ�ԣ�
�˲�ε�����̴�Ԫ�꣨1265�꣩ئһ��ͬ�ڽ�ʿ��Ϊ�Ž�����������
�»���Ϊ������Ԫ�����꣨l082�������״Ԫ�������Ƿ�ּ��׫������
���ء����򳹾����书�����¡������澭������������������������ƽ
��Ժ�����Ļ���ء�
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"meishanpo",
		"southdown" : __DIR__"xishan",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng": random(2)+1,
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1450);
	set("coor/y", -6170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
