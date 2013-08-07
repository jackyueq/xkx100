// Room: /d/jiaxing/nanhu1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void init();
int do_out();

void create()
{
	set("short", "�����Ϻ�");
	set("long", @LONG
�������̲������Ϻ������ϼ�ֻ�������ε������ϵ��οͺ���¥
Ů������Ц����ˮ���û�д��Ƕɲ���ȥ�ġ�����֪��˭�ں��׶���
һЩľ׮��׮��Ǳ��ˮ��֮��һ����ĵط�����ʹ�ǲ����Ṧ��������
ȥҲ����ˮ��Ư�����ӡ��ƺ�ˮ������Щʲô����������Ǳ (out)�º�
ȥ��Ѱʲô, ��Ҳ��֪�������Ρ�ֻ�����˴����ں����ҵ���ʲô��
����
LONG );
	set("exits", ([
		"south"     : __DIR__"yanyu",
		"northwest" : __DIR__"nanhu",
		"southeast" : __DIR__"road",
	]));
	set("outdoors", "jiaxing");
        set("objects", ([
                "/clone/medicine/vegetable/heye" : random(2),
        ]));
	set("coor/x", 1520);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_out","out");
}

int do_out()
{
	object me = this_player();
	message_vision("$N����Ծ�𣬿���һ�����﷭����ͷ�½��ϣ��˵�һ��Ǳ����в�����.\n", me);
	me->move("/d/npc/m_weapon/tan/tan1");
	return 1;
}