// anshazhe.c ��ɱ��
inherit NPC;
#include "aninit.h"

void create()
{
	string weapon;
	int i;

	i = random(sizeof(name_msg));
	set_name(name_msg[i], ({ long_id[i], short_id[i] }) );
	set("gender", random(2)>0 ? "Ů��" : "����" );
	set("age", 15 + random(40) );
	set("long","һ����ͨ���ˣ�������Ⱥ��û��һ��ͻ��֮����\n");

	weapon = weapon_msg[random(sizeof(weapon_msg))];
	setup();
	carry_object(weapon);
	carry_object("/clone/misc/cloth")->wear();
}

