// head.c -�Դ�
#include <ansi.h>
inherit ITEM;
int decayed;

void create()
{
	set_name(RED"ͷ­"NOR, ({ "head"}));
	set_weight(300);
	set("unit", "��");
	set("value", 0);
	decayed = 0;
	set("long",RED"һ����Ѫ���ܵ��׼����뷢ɢ�ң���Ѫ������������\n"NOR);
	if( clonep(this_object()) )
		call_out("decay", 300, 1);
}

int is_corpse()    { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;
	if( query("shihui") )
	{
		phase = 0;
		decayed = 0;
		delete("shihui");
		call_out("decay", 600, 1);
	}
	switch(phase) {
		case 1:
			say(query("name")+"��ʼ�����ˣ�����һ�����ŵĶ����\n");
			set_name("���õ�ͷ­", ({ "decomposite head"}) );
			set("long","���ͷ­��Ȼ�Ѿ�������һ��ʱ���ˣ�һ�ɶ������Ѫ�ȵ�ζ����\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			say( query("name") + "���紵Ǭ�ˣ����һ������ͷ��\n" );
			set_name("�ײҲҵ�����ͷ", ({ "head bone" }) );
			set("long", "�������ͷ�Ѿ�������������Щʱ���ˡ�\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			say("һ��紵������" + query("name") + "���ɹǻҴ�ɢ�ˡ�\n" );
			if( environment() ) {
				object *inv;
				int i;

				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) inv[i]->move(environment());
			}
			destruct(this_object());
			break;
	}
}

