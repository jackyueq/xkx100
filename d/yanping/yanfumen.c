// Room: /d/yanping/yanfumen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�Ӹ���");
	set("long", @LONG
�Ӹ��ž��Ǵ�ˮ���ˣ���ǰ����ɱ�ɷ���ֱͨʡ�Ǹ��ݡ���ƽ��
���̳��ܣ����з�������󴻢�ᣬ�Թ�����Ϊ����Ȩı�ұ�������
    פ���ͷ�Ӹ�¥���������³�����ȫ��ˮ��������ɽ����¥������
��ɽ�Ʊ����������Ĺ��������ѹ�������ռϪɽ֮�ۣ���ˮ½֮�ᣬΪ
����֮���ʡ��֮���ϣ����С�ͭ��ƽ�������䡱֮�����ʹط�����
���ᵡ��¡�������Թ���үʳ���˷����ͷ���ƽ������
LONG );
	set("exits", ([
		"west"      : __DIR__"road2",
		"north"     : __DIR__"road1",
		"southeast" : __DIR__"longjindu",
	]));
        set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1500);
	set("coor/y", -3000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
