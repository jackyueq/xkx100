// Room: /d/yanping/yanshoumen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������ƽ�����ţ��Ÿ߿����ɣ���ש���ͣ����ݵ�¥��������
��¥������ү֣�ɹ�Ϊ��¡�����ӵļݣ�������ս��������ʫ������
�ῢ(ɽ��)��һ�أ���겸��ݸ�ǧ�塣����Ͽ����Ϫˮ������ǰ����
ɽ���Ҷ����������䣬��ɽ��ȥ�����С�������������У����ǹ���
���ա������⸡��ͨ����Ϫ�ϰ��ľŷ�ɽ��
LONG );
	set("exits", ([
		"north"     : __DIR__"road2",
		"southdown" : __DIR__"fuqiao2",
	]));
        set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
