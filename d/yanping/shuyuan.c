// Room: /d/yanping/shuyuan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "��ƽ��Ժ");
	set("long", @LONG
�����μζ����꣬���س���ھŷ�ɽ´���°�¹��Ժ��������ƽ��
Ժ��Ϊ����ƽ���͡���ѧ֮������Ժ���ھŷ�ɽ�ųơ����Ρ���ɽ��
֮�����˴�������ǧ�˰ݣ�ҹ����յ�ơ���Ϊ��ƽ��ˮ����֮�ء�����
����һ�������������һ����ܣ������˸��ֵ伮���������ݰ��ܱʼ�
�飬�ƺ��ڸ�����ôѧ�ʡ�ԭ�������ǻ��Ѱ��������ޡ����ٵ��ء���
��ʦ��ͨ����ϰ�ڹ��⹦������Ϊһλ�书����֣�д��������������
�š������澭����
LONG );
	set("exits", ([
		"west"      : __DIR__"9fengshan",
		"southeast" : __DIR__"yuandong",
	]));
	set("objects", ([
		__DIR__"npc/huangshang" : 1,
	]));
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}
