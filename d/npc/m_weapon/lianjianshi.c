// ROOM lianjianshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����������Ŷ��������������ܻ���û�����̣�������Լ���ܿ���
�߰ߵ�Ѫ����ż���ܿ����ļ������ƺ�Ҳ���˽��ı�����һ����������
�ŵġ�¶�����һ���޴��¯�ӣ�ð����������ף����ҵ���������
һ����ѣ��ԭ�������������ڼ�����������
LONG );
	set("exits", ([
		"south" : "/d/xingxiu/shamo3",
	]));
	set("objects",([
		__DIR__"npc/shijian" :1,
	]));
	set("coor/x", -30000);
	set("coor/y", 1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
